from web3 import Web3

# Connect to a local or Infura Ethereum node
INFURA_URL = 'https://mainnet.infura.io/v3/YOUR_INFURA_PROJECT_ID'
web3 = Web3(Web3.HTTPProvider(INFURA_URL))

# Ethereum account details (replace with your wallet and private key)
ACCOUNT_ADDRESS = 'YOUR_WALLET_ADDRESS'
PRIVATE_KEY = 'YOUR_PRIVATE_KEY'

def store_result_on_chain(name, score):
    if not web3.isConnected():
        return 'Blockchain connection failed.'

    # Simple data to store on the chain
    data = f"Name: {name}, Score: {score}"
    
    # Transaction parameters
    transaction = {
        'to': ACCOUNT_ADDRESS,
        'value': web3.toWei(0, 'ether'),
        'gas': 2000000,
        'gasPrice': web3.toWei('50', 'gwei'),
        'nonce': web3.eth.getTransactionCount(ACCOUNT_ADDRESS),
        'data': web3.toHex(text=data),
    }

    # Sign and send the transaction
    signed_txn = web3.eth.account.sign_transaction(transaction, private_key=PRIVATE_KEY)
    tx_hash = web3.eth.send_raw_transaction(signed_txn.rawTransaction)
    return web3.toHex(tx_hash)
