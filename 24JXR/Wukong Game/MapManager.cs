// Date: 2024/09/15
// Author: ChaomengOrion

namespace OPP.Wukong
{
    public class MapManager
    {
        public MapManager(string[] inputs, int w, int h, MapObjectFactory factory)
        {
            this.w = w;
            this.h = h;
            map = new MapObject[w, h];
            entities = [];
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    map[j, i] = factory.CreatMapObject(inputs[i][j]);
                    map[j, i].postion = new Vector2(j, i);
                    if (map[j, i] is Entity entity) entities.Add(entity); // 如果MapObject为Entity，加入entities以便调用OnTick事件
                }
            }
            m_Instance = this;
            Console.Write("\u001b[s");
            Console.Write("\u001b[?25l");
        }

        public static MapManager Instance
        { 
            get 
            {
                return m_Instance!;
            } 
        }

        public void OnTick()
        {
            foreach (Entity entity in new HashSet<Entity>(entities)) entity.OnTick();
            if (isEnd)
            {
                Console.WriteLine("\u001b[K\u001b[1;34mGame end.\u001b[0m");
                Console.Write("\u001b[?25h");
                return;
            }
            Draw(ref map, w, h, tickCnt);
            tickCnt++;
        }

        private static void Draw(ref MapObject[,] map, int w, int h, int tick)
        {
            Console.Write("\u001b[u");
            Console.Write("\u001b[s");
            Console.WriteLine($"\u001b[1;34mCurrent tick count: {tick}\u001b[0m");
            Console.WriteLine(new string('=', w));
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    Console.Write(GetIcon(map[j, i]));
                }
                Console.Write('\n');
            }
            Console.WriteLine(new string('=', w));
        }

        public static string GetIcon(MapObject mapObject)
        {
            string icon = mapObject.GetIcon();
            if (mapObject.GetLayer() == MapObject.Layer.MAP)
            {
                return $"\u001b[40;36m{icon}\u001b[0m";
            }
            else
            {
                return icon;
            }
        }

        public MapObject[,] map;
        public int w, h;
        public List<Entity> entities;
        public bool isEnd = false;

        private static MapManager? m_Instance = null;
        private int tickCnt = 0;
    }
}
