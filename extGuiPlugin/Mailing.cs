using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;

namespace guiPlugin
{
    class Mailing
    {
        MailMessage mail;
        SmtpClient client;
        public Mailing()
        {

        }
        public void SendMail(string host, int port, string userName, string password, string from, string to, string subject, string body, string attachPath)
        {

            client = new SmtpClient(host, port); //SMTP Server von Hotmail und Outlook. 
            //client.Timeout = 50000;
            mail = new MailMessage(from, to, subject, body);
            mail.Attachments.Add(new Attachment(attachPath));

            //Console.WriteLine("email gönderiliyor..");
            client.Credentials = new System.Net.NetworkCredential(userName, password);//Anmeldedaten für den SMTP Server 
            client.EnableSsl = true; //Die meisten Anbieter verlangen eine SSL-Verschlüsselung 
            client.Send(mail); //Senden 

        }
    }
}
