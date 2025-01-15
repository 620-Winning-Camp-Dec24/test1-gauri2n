const form = document.getElementById('iqForm');
const resultDiv = document.getElementById('result');

form.addEventListener('submit', async (e) => {
  e.preventDefault();

  const name = document.getElementById('name').value;
  const answers = [
    parseInt(form.q1.value),
    parseInt(form.q2.value),
  ];

  try {
    const response = await fetch('/api/calculate', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ name, answers }),
    });

    const data = await response.json();
    resultDiv.innerText = `Your IQ score is: ${data.score}`;
  } catch (err) {
    resultDiv.innerText = 'Error calculating IQ.';
  }
});
