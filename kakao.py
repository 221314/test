import requests
import json

url = 'https://kauth.kakao.com/oauth/token'
client_id = '0269b1387819e488104e8def1dc3d096'
redirect_uri = 'http://localhost/main.php'
code = 'w342TqYH6Bc8gfcilBAjdNbd6LVDwPJ2j891DbR0isnjhs-HOHAMMbCIWB4sOM1X2Ti-9wopyNkAAAGChozvWg'

data = {
    'grant_type':'authorization_code',
    'client_id': client_id,
    'redirect_uri': redirect_uri,
    'code': code,
    }

response = requests.post(url, data=data)
tokens = response.json()

#발행된 토큰 저장
with open("token.json","w") as kakao:
    json.dump(tokens, kakao)
