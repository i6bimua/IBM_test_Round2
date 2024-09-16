// Date: 2024/09/15
// Author: ChaomengOrion

using System.Reflection;

namespace OPP.Wukong
{
    public class MapObjectFactory
    {
        private readonly Dictionary<char, string> _bindMap = new();

        public void BindEntity<T>(char id) where T : MapObject
        {
            if (_bindMap.ContainsKey(id)) return;
            _bindMap.Add(id, typeof(T).FullName!);
        }

        public MapObject CreatMapObject(char id)
        {
            if (!_bindMap.TryGetValue(id, out string? value)) throw new Exception($"No id: {id} found");
            Type t = Assembly.GetCallingAssembly().GetType(value)!; // 反射拿到类
            MapObject entity = (Activator.CreateInstance(t) as MapObject)!; // 创建类的实例对象
            return entity;
        }

        public delegate void Logger(string? message);

        public void LogBindInfo(Logger logger)
        {
            foreach (var pair in _bindMap)
            {
                var obj = CreatMapObject(pair.Key);
                logger($"\u001b[1;34m{obj.Name} - \u001b[0m{MapManager.GetIcon(obj)}");
            }
        }
    }
}
