from flask import Flask, request, jsonify, render_template
from flask_sqlalchemy import SQLAlchemy
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

# Database configuration
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

# Database Model
class IQResult(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(100), nullable=False)
    answers = db.Column(db.String(200), nullable=False)
    score = db.Column(db.Integer, nullable=False)

# Endpoint to calculate IQ
@app.route('/api/calculate', methods=['POST'])
def calculate_iq():
    data = request.get_json()
    name = data.get('name')
    answers = data.get('answers')

    # Sample scoring logic
    correct_answers = [1, 2, 3, 4, 5]
    score = sum(20 for i, ans in enumerate(answers) if ans == correct_answers[i])

    # Save result to the database
    result = IQResult(name=name, answers=str(answers), score=score)
    db.session.add(result)
    db.session.commit()

    return jsonify({'message': 'IQ calculated successfully', 'score': score})

# Serve the frontend
@app.route('/')
def index():
    return render_template('index.html')

if __name__ == '__main__':
    db.create_all()
    app.run(debug=True)
