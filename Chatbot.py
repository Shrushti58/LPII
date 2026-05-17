print('Welcome to ChatBot Support')
print("Enter 'exit' to end the chat")

while True:
    user=input('You : ').lower()

    if user=="exit":
        print('Bot: Thankyou!')
        break

    elif user in ['hi','hello','hey']:
        print('Bot: Hey! How can I help you??')

    elif 'price' in user or 'cost' in user:
        print('Bot: Our product prices start from Rs. 999.')

    elif 'delivery' in user:
        print('Bot: We deliver Product in 3-5 Days')

    elif 'contact' in user:
        print('Bot: suuport@gmail.com')

    else:
        print('Bot: Sorry I cant understand it.Please try again later!')
