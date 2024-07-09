import requests
import serial
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

def sendemail():

    # Email configuration
    smtp_server = 'smtp.gmail.com' 
    smtp_port = 587  # 587 is commonly used for TLS
    sender_email = '-------------------' 
    receiver_email = '==================' 
    password = '**** **** **** ****' 
    # Create a message
    subject = 'Alert!!! GAS detected.'
    message = 'This is to inform you that the gas has been leaked and be cautious!!'
    msg = MIMEMultipart()
    msg['From'] = sender_email
    msg['To'] = receiver_email
    msg['Subject'] = subject
    msg.attach(MIMEText(message, 'plain'))

    # Connect to the SMTP server
    try:
        server = smtplib.SMTP(smtp_server, smtp_port)
        server.starttls()  
        server.login(sender_email, password)
        # Send the email
        server.sendmail(sender_email, receiver_email, msg.as_string())
        print("Email sent successfully")

    except Exception as e:
        print(f"Email could not be sent. Error: {str(e)}")
    finally:
        server.quit()
    





def check(ser) :
    count = 0
    gas_val = 0
    while(True) :
        time.sleep(2)
        line = str(ser.readline().decode())
        if line.strip().isdigit():
            gas_val = int(line)
        if gas_val >= 25:
            count=count+1
        if count == 10:
            sendemail()
            count = 0

if __name__ == '__main__' :
    ser = serial.Serial('COM6', 9600, timeout=1)
check(ser)