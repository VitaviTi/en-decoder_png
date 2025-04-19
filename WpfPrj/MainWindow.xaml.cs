using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using static WpfPrj.MainWindow;
using Microsoft.Win32;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
//using System.Windows.Forms;

namespace WpfPrj
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    /// 

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        public void OpenFileDialog(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.OpenFileDialog openFileDialog = new Microsoft.Win32.OpenFileDialog();
            openFileDialog.ShowDialog();
            openFileDialog.FileOk += UserCancel();
            UserPath.Text = openFileDialog.FileName;
        }
        public static CancelEventHandler UserCancel() => null;

        //[DllImport("En-decoder_png.dll")]
        //private extern 
    }
}