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






        // -----------------------------------------------------------------------------------
        //public void OpenFi(object sender, RoutedEventArgs e)
        //{
        //    Microsoft.Win32.OpenFileDialog openFileDialog = new Microsoft.Win32.OpenFileDialog();
        //    openFileDialog.ShowDialog();
        //    openFileDialog.FileOk += DudePressTheButton();



        //    //if (openFileDialog.ShowDialog() == true)
        //    //{

        //    //}
        //}
        //void SaveF(object sender, RoutedEventArgs e)
        //{
        //    Microsoft.Win32.SaveFileDialog saveFileDialog = new Microsoft.Win32.SaveFileDialog();
        //}

        //static CancelEventHandler DudePressTheButton()
        //{
        //    return null;
        //}
        //CancelEventHandler handler = new CancelEventHandler(object sender, CancelEventArgs e);
        // --------------------------------------------------------------------------------------
        //    Grid grid = new Grid();
        //    grid.ShowGridLines = true;
        //    for (int i = 0; i < 5; i++)
        //    {
        //        grid.ColumnDefinitions.Add(new ColumnDefinition());
        //    }
        //    for (int j = 0; j < 10; j++)
        //    {
        //        grid.RowDefinitions.Add(new RowDefinition());
        //    }


        //    System.Windows.Controls.Button button = new System.Windows.Controls.Button();
        //        button.MaxHeight = 140;
        //        button.MaxWidth = 300;
        //        button.Content = "Каталог_Шарп";
        //        button.VerticalAlignment = System.Windows.VerticalAlignment.Center;
        //        button.HorizontalAlignment = System.Windows.HorizontalAlignment.Center;
        //        button.Click += OpenFolderBrowserDialog;

        //    System.Windows.Controls.Button button1 = new System.Windows.Controls.Button();
        //        button1.MaxHeight = 140;
        //        button1.MaxWidth = 500;
        //        button1.Content = "Подтвердить путь";
        //        button1.VerticalAlignment = System.Windows.VerticalAlignment.Center;
        //        button1.HorizontalAlignment = System.Windows.HorizontalAlignment.Center;
        //        button1.Click += AcceptToPath;

        //    System.Windows.Controls.Button button2 = new System.Windows.Controls.Button();
        //        button2.MaxHeight = 140;
        //        button2.MaxWidth = 500;
        //        button2.Content = "Путь к файлу";
        //        button2.VerticalAlignment = System.Windows.VerticalAlignment.Center;
        //        button2.HorizontalAlignment = System.Windows.HorizontalAlignment.Center;
        //        button2.Click += OpenFile;

        //    grid.Children.Add(button);
        //    grid.Children.Add(button1);
        //    grid.Children.Add(button2);

        //    Grid.SetColumn(button, 3);
        //    Grid.SetRow(button, 3);

        //    Grid.SetColumn(button1, 1);
        //    Grid.SetRow(button1, 1);

        //    Grid.SetColumn(button2, 2);
        //    Grid.SetRow(button2 , 2);

        //    TextBlock textBlock = new TextBlock();
        //    textBlock.Width = 100;
        //    textBlock.Height = 50;
        //    textBlock.HorizontalAlignment = System.Windows.HorizontalAlignment.Center;
        //    textBlock.VerticalAlignment = System.Windows.VerticalAlignment.Center;
        //    textBlock.TextWrapping = System.Windows.TextWrapping.Wrap;
        //    textBlock.Background = new SolidColorBrush(System.Windows.Media.Color.FromRgb(123, 123, 123));
        //    TextBlock = textBlock;

        //    grid.Children.Add(textBlock);


        //    this.Content = grid;
        //}
        //void AcceptToPath(object sender, RoutedEventArgs e)
        //{
        //    string path = FolderBrowserDialog.SelectedPath;
        //    //Path = path;
        //    TextBlock.Text = path;

        //}
        //void OpenFolderBrowserDialog(object sender, RoutedEventArgs e)
        //{
        //    FolderBrowserDialog folderBrowserDialog = new FolderBrowserDialog();            
        //    folderBrowserDialog.ShowDialog();
        //    FolderBrowserDialog = folderBrowserDialog;
        //}
        //void OpenFile(object sender, RoutedEventArgs e)
        //{
        //    OpenFileDialog openFileDialog = new OpenFileDialog();
        //    openFileDialog.ShowDialog();
        //    FolderBrowserDialog.SelectedPath = openFileDialog.FileName;
        //}



    }
}