import http.client
import time
import json
import base64


def get_content():

    conn = http.client.HTTPSConnection("api.github.com")


    headersList = {
    "Accept": "*/*",
    "User-Agent": "Thunder Client (https://www.thunderclient.com)",
    "Authorization": "Basic YnVmbGFsbG86Z2hwXzVJZDRuOEZQQlgyb045eWUwTDdMbGNpMkZiUkNlSDJUallRUw==" 
    }

    #open a file and read it line by line storit on a vector
    i = 0
    repos = open("repos_scrap.txt", "r")
    token = repos.read()

    f_o = open('content_encrypted.txt', 'w')
    # for line in token:
    for line in token.split('\n'):
        time.sleep(0.5)
        payload = ""

        conn.request("GET", line, payload, headersList)
        response = conn.getresponse()
        result = response.read()

        # print(result.decode("utf-8"))

        data = json.loads(result.decode("utf-8"))

        content = data["content"]

        f_o.write(content + '\n')
        i += 1
        if i < 5:
            print(content)
    f_o.close()
    repos.close()


def decode_base64_file(input_file, output_file):

    # Read the base64-encoded string from the file
    with open(input_file, 'r') as f:
        encoded_content = f.read()
    f = open(output_file, 'wb')
    sep = '====================================================================================================================\n\n===================================================================================================================='
    for line in encoded_content.split('\n\n'):
    # Decode the string
        decoded_content = base64.b64decode(line)
        # Write the decoded content to a new file
        f.write(decoded_content)
        f.write(sep.encode('utf-8'))
        # print(decoded_content)
    f.close()

# def main
get_content()
decode_base64_file('content_encrypted.txt', 'decoded.txt')