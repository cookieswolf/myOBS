
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CLROBS;
using System.Windows;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Drawing;

namespace guiPlugin
{


    public class guiPluginHook : AbstractPlugin
    {
        
        public guiPluginHook()
        {

            Name = "BTM TV Studio";
            Description = "Plugin for the Control of the OBS by an external GUI";
            
        }

        public override bool LoadPlugin()
        {
            Rectangle r;
            r = Screen.AllScreens[Screen.AllScreens.Length - 1].WorkingArea;


            Window window = new Window
            {
                Title = "BTM TV Studio",
                Content = new guiControl(),
                WindowStyle = WindowStyle.None,
                ShowInTaskbar = false,
                AllowsTransparency = true,
                Background = System.Windows.Media.Brushes.Transparent

                //  WindowStartupLocation = WindowStartupLocation.Manual

            };
            

            window.Top = r.Top;
            window.Left = r.Left;
            window.Width = r.Width;
            window.Height = r.Height;

            window.Show();

            API.Instance.SetFullscreen(true);
            API.Instance.StartStopRecordingReplayBuffer();
            return true;
        }
    }
}
