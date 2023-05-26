from selenium import webdriver

# set up a web driver and open the WhatsApp web page
driver = webdriver.Chrome()
driver.get("https://web.whatsapp.com")

# wait for the user to scan the QR code to login
input("Press enter after scanning the QR code...")

# define a function to check if a phone number is registered on WhatsApp
def is_registered(number):
    input_box = driver.find_element_by_xpath('//input[@title="Search or start new chat"]')
    input_box.clear()
    input_box.send_keys(number)
    try:
        title = driver.find_element_by_xpath('//div[@class="_2wP_Y"]//span[@title]')
        return True
    except:
        return False

# usage example
if is_registered("+6123456789"):
    print("This number is registered on WhatsApp")
else:
    print("This number is not registered on WhatsApp")