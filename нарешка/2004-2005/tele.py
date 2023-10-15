import telebot;
bot = telebot.TeleBot('6683182808:AAFSo2EEeVtj6eBlRuuGg9cZZCAkapy6EO8')

n = int(input())

@bot.message_handler(content_types=['text'])
def g():
    bot.send_message(1621068777, n)
g()

'''

6683182808:AAFSo2EEeVtj6eBlRuuGg9cZZCAkapy6EO8

'''