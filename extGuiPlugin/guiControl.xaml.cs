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
using System.Windows.Shapes;
using System.Windows.Threading;
using CLROBS;
using System.IO;


namespace guiPlugin
{

    /// <summary>
    /// Interaction logic for guiControl.xaml
    /// </summary>
    /// 

    public partial class guiControl : UserControl
    {
        Timer t;
        System.Threading.Thread WaiterThread;
        string FilePath;
        int resim;
        const int RESIM = 3;
        public guiControl()
        {
            InitializeComponent();
            t = new Timer();
            t.Elapsed += t_Elapsed;
            resim = 0;
            
            //this.Dispatcher.Invoke(GetRec);
            //recording = DllHelper.COBSGetRecording();
            
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
        }
        
        private void EnableBut()
        {
            this.butCek.IsEnabled = true;
        }

        private void WaitRec()
        {
            while (!API.Instance.GetRecording())
            {
                System.Threading.Thread.Sleep(50); 
            }
            t.Start();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if (!API.Instance.GetRecording())
            {
                t.Interval = 10100;
                API.Instance.StartStopRecording();
                this.butCek.IsEnabled = false;
                WaiterThread = new System.Threading.Thread(WaitRec);
                WaiterThread.Start();

                
                //MessageBox.Show("Çek basıldı");
            }
            
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
            resim = ++resim % RESIM + 1;
            for (int i = 1; i <= RESIM; i++)
            {
                API.Instance.SetSourceRender(string.Format("Fon {0}", i), i==resim);
            }

        }
    }
}
