using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace WpfPrj
{

    public interface IDialogService
    {
        //public string FilePath { get; set; }   // путь к выбранному файлу
        static public TextBlock MyTextBlock { set; get; }
        static public Button MyButton { set; get; }

        public void OpenFileDialog(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.OpenFileDialog openFileDialog = new Microsoft.Win32.OpenFileDialog();
            openFileDialog.ShowDialog();
            openFileDialog.FileOk += UserCancel();
            MyTextBlock.Text = openFileDialog.FileName;
        }
        public static CancelEventHandler UserCancel()
        {
            return null;
        }
    }
}
