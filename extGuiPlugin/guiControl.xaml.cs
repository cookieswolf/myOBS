using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Timers;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
//using System.Windows.Shapes;
using System.Windows.Threading;
using CLROBS;
using System.IO;
//using Vlc.DotNet.Wpf;
using Vlc.DotNet.Forms;
using System.Reflection;
using extGuiPlugin;

namespace guiPlugin
{

    /// <summary>
    /// Interaction logic for guiControl.xaml
    /// </summary>
    /// 

    public partial class guiControl : UserControl
    {
        Timer t;
        Timer count;
        Timer delayedStart;
        //VlcControl myControl;
        int countTimer;
        System.Threading.Thread WaiterThread;
        videoPlay vt;
        string FilePath;
        int resim;
        const int RESIM = 6;
        const int TIMERMAX = 5;
        public guiControl()
        {
            InitializeComponent();
            //myControl = new VlcControl();
            //System.Windows.Forms.Panel p = new System.Windows.Forms.Panel();
            t = new Timer();
            count = new Timer();
            delayedStart = new Timer();
            count.Elapsed += count_Elapsed;
            t.Elapsed += t_Elapsed;
            delayedStart.Elapsed += delayedStart_Elapsed;
            //delayedStart.Interval = 1000;
            
            resim = 0;
            vt = new videoPlay();
            //wfHost.BringIntoView();
            
            
            
        }

        void delayedStart_Elapsed(object sender, ElapsedEventArgs e)
        {
            delayedStart.Stop();
            this.Dispatcher.Invoke((Action)(StartVideo));
            //vt.Play(FilePath);
            //throw new NotImplementedException();
        }

        void count_Elapsed(object sender, ElapsedEventArgs e)
        {
            if (countTimer >= 0)
            {
                for (int i = 1; i <= TIMERMAX; i++)
                {
                    API.Instance.SetSourceRender(string.Format("T{0}", i), i == countTimer);
                }
                count.Interval = 1000;
                countTimer--;
                count.Start();
            }
            else
            {
                count.Stop();
                //for (int i = 1; i <= TIMERMAX; i++)
                //{
                //    API.Instance.SetSourceRender(string.Format("T{0}", 1), false);
                //}
                API.Instance.StartStopRecording();
                //this.butCek.IsEnabled = false;
                WaiterThread = new System.Threading.Thread(WaitRec);
                WaiterThread.Start();
               
                //now start recording

            }
            //throw new NotImplementedException();
        }
        
        void t_Elapsed(object sender, ElapsedEventArgs e)
        {
            t.Stop();

            if (API.Instance.GetRecording())
            {
                API.Instance.StartStopRecording();
                FilePath = API.Instance.GetLastOutputFile();
                //recording = false;
            }
            this.Dispatcher.Invoke((Action)(EnableBut));
            WaiterThread.Abort();
            delayedStart.Interval = 2000;
            delayedStart.Start();
            //vt.Play(FilePath);
            
        }
        
        private void EnableBut()
        {
            this.butCek.IsEnabled = true;
        }

        private void StartVideo()
        {
            vt.Play(FilePath);
            //myControl.Visibility = Visibility.Visible;
            //myControl.MediaPlayer.
            //myControl.Play(new Uri(FilePath));
            //videoPlay.Source = new Uri(FilePath);
            
            //videoPlay.IsEnabled = true;
            //videoPlay.Play();
            //videoPlay.set = true;
        }
        private void WaitRec()
        {
            while (!API.Instance.GetRecording())
            {
                System.Threading.Thread.Sleep(50); 
            }
            t.Start();
        }
        private void Cek()
        {
            if (!API.Instance.GetRecording())
            {
                t.Interval = 5100;
                count.Interval = 1000;
                countTimer = TIMERMAX;
                count.Start();
                //API.Instance.StartStopRecording();
                this.butCek.IsEnabled = false;
                //WaiterThread = new System.Threading.Thread(WaitRec);
                //WaiterThread.Start();
                //MessageBox.Show("Çek basıldı");
            }
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Cek();
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            if (FilePath != null)
            {
                FileInfo fi = new FileInfo(FilePath);
                if (fi.Exists)
                {
                    //MessageBox.Show("YEAH!");
                    Mailing m = new Mailing();
                    m.SendMail("smtp.gmail.com", 587, "btmtest16@gmail.com", "TestBtm16", "btmtest16@gmail.com", tbMail.Text, "greetings", "hi", FilePath);
                }
            }

        }

        private void butDegistir_Click(object sender, RoutedEventArgs e)
        {
            if (resim == RESIM)
                resim = 1;
            else
                resim++;
            for (int i = 1; i <= RESIM; i++)
            {
                API.Instance.SetSourceRender(string.Format("Fon {0}", i), i==resim);
            }

        }

        private void butOyna_Click(object sender, RoutedEventArgs e)
        {
            //System.Windows.Forms.OpenFileDialog openFileDialog1= new System.Windows.Forms.OpenFileDialog();
            //if (openFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            //{
            //    FilePath = openFileDialog1.FileName;
            //    //vt = new videoPlay();
            //    //myControl.Size = new System.Drawing.Size(1024, 768);
            //    //myControl.Play(new Uri(s));
            //}
            if (File.Exists(FilePath))
            {
                vt.Play(FilePath);
            }
            else
            {
                System.Threading.Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("en-US");
                if(MessageBox.Show("Cekim yapilmamis\nSimdi bir Cekime baslamak istermisin?","Hata!",MessageBoxButton.OKCancel)==MessageBoxResult.OK)
                {
                    Cek();
                }
            }

        }
    }
}
