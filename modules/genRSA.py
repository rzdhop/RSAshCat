import rsa
import sys

def genKey(bitsize:int) -> tuple:
        return rsa.newkeys(bitsize)
    
bitSize = int(sys.argv[1])
(pubKey, privKey) = genKey(bitSize)

with open(f"assets/pubKey_{bitSize}bit.pem", 'w+') as keyFileStream:
        keyFileStream.write(pubKey.save_pkcs1().decode('utf-8'))
        
with open(f"assets/privKey_{bitSize}bit.key", 'w+') as keyFileStream:        
        keyFileStream.write(privKey.save_pkcs1().decode('utf-8'))