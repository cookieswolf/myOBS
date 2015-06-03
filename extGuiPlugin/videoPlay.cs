using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace extGuiPlugin
{
    public partial class videoPlay : Form
    {
        Uri videopath;
        Vlc.DotNet.Forms.VlcControl vlcControl1 = new Vlc.DotNet.Forms.VlcControl();
        delegate void MyStop();
        MyStop myDelegate;
        Rectangle r;
        public videoPlay()
        {
            
            InitializeComponent();
            panel1.Controls.Add(vlcControl1);
            vlcControl1.BackColor = System.Drawing.Color.Black;
            vlcControl1.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            vlcControl1.Location = new System.Drawing.Point(0, 0);
            vlcControl1.Size = panel1.Size;
            vlcControl1.Visible = true;
            vlcControl1.VlcLibDirectoryNeeded += vlcControl1_VlcLibDirectoryNeeded;
            vlcControl1.Stopped += vlcControl1_Stopped;
            vlcControl1.EndReached += vlcControl1_EndReached;
            r = Screen.AllScreens[Screen.AllScreens.Length - 1].WorkingArea;
            StartPosition = FormStartPosition.Manual;
            Location = new Point(r.X + 392 , r.Y + 516);
            //Top += (r.Width / 2) - (Width / 2) ;
            //Left -= 300;
            //Width = r.Width;
            //Height = r.Height;

            this.Visible = false;
            myDelegate = new MyStop(MeStop);
            //videopath = path;    
            //vlcControl1.Size = new System.Drawing.Size(280, 280);
            //vlcControl1.Visible = true;

            //vlcControl1.Play(new Uri(path));
            
        }
        public void Play(string path)
        {
            this.Visible = true; 
            videopath = new Uri(path);
            vlcControl1.Play(videopath);
        }
        public void MeStop()
        {
            //vlcControl1.Stop();
            this.Visible = false;
        }
        void vlcControl1_EndReached(object sender, Vlc.DotNet.Core.VlcMediaPlayerEndReachedEventArgs e)
        {
            Invoke(myDelegate);
            //this.Visible=false;
        }
        

        void vlcControl1_Stopped(object sender, Vlc.DotNet.Core.VlcMediaPlayerStoppedEventArgs e)
        {
            this.Visible = false;
            //throw new NotImplementedException();
        }

        void vlcControl1_VlcLibDirectoryNeeded(object sender, Vlc.DotNet.Forms.VlcLibDirectoryNeededEventArgs e)
        {
            var currentAssembly = Assembly.GetCallingAssembly();
            //var currentDirectory = new FileInfo(currentAssembly.Location).DirectoryName;
            //if (currentDirectory == null)
            //return;
            if (AssemblyName.GetAssemblyName(currentAssembly.Location).ProcessorArchitecture == ProcessorArchitecture.X86)
                e.VlcLibDirectory = new DirectoryInfo(@"f:\lib\x86\");
            else
                e.VlcLibDirectory = new DirectoryInfo(@"f:\lib\x64\");
            //throw new NotImplementedException();
        }

        private void videoPlay_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (vlcControl1.IsPlaying)
            {
                vlcControl1.Stop();
                //vlcControl1.med
                e.Cancel = true;
                //vlcControl1.Dispose();
                //Thread.Sleep(100);
                //while (vlcControl1.State != MediaStates.Stopped) ;
            }
            //vlcControl1.Hide();

        }
    }
}
