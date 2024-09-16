// Date: 2024/09/15
// Author: ChaomengOrion

using System.Text;

namespace OPP.Wukong
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string path;
            if (args.Length == 0) 
            {
                path = Path.Combine(Directory.GetCurrentDirectory(), "map.txt");
                if (!File.Exists(path))
                {
                    Console.WriteLine("未找到map.txt，请在传入参数中输入map.txt地址");
                    PreExit();
                    return;
                }
            }
            else
            {
                path = args[0];
            }
            Console.WriteLine($"\u001b[1;34mReading map from [\u001b[1;4;32m{path}\u001b[0m\u001b[1;34m] ...\u001b[0m");
            int w, h;
            string[] inputs;
            try
            {
                using StreamReader sr = new(path, Encoding.UTF8);
                string[] s = sr.ReadLine()!.Split(' ');
                w = Convert.ToInt32(s[0]);
                h = Convert.ToInt32(s[1]);
                inputs = new string[h];
                Console.WriteLine("\u001b[1;34mInput map:\u001b[0m");
                Console.WriteLine(new string('=', w));
                for (int i = 0; i < h; i++)
                {
                    inputs[i] = sr.ReadLine()!;
                    Console.WriteLine("\u001b[1;33m" + inputs[i] + "\u001b[0m");
                }
                Console.WriteLine(new string('=', w));
            }
            catch (Exception e)
            {
                Console.WriteLine("The file could not be read:");
                Console.WriteLine(e.Message);
                PreExit();
                return;
            }

            MapObjectFactory factory = new();
            factory.BindEntity<Floor>('.'); // 地板 - .
            factory.BindEntity<Trap>('#'); // 障碍物 - #
            factory.BindEntity<Wukong>('W'); // 悟空 - W
            factory.BindEntity<EnemyKobold>('O'); // 小妖怪 - O
            factory.BindEntity<EnemyBoss>('X'); // 头目 - X
            factory.LogBindInfo(s => Console.Write(s + " | "));
            Console.WriteLine();

            // 实例化地图
            MapManager manager = new(inputs, w, h, factory);

            while (!manager.isEnd)
            {
                manager.OnTick();
                Thread.Sleep(200);
            }

            PreExit();
        }

        static void PreExit()
        {
            Console.WriteLine("按任意键退出...");
            Console.ReadKey();
        }
    }
}