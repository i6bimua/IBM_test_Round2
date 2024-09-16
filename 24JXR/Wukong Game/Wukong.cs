// Date: 2024/09/15
// Author: ChaomengOrion

namespace OPP.Wukong
{
    public class Wukong : Entity
    {
        public override string Name => "悟空";

        public override string GetIcon() => "\u001b[1;33m@\u001b[0m";

        private Astar? astar = null;
        private Entity? target = null;
        List<Vector2>? path = null;

        public override void OnTick()
        {
            if (target == null)
            {
                target = MapManager.Instance.entities.Find(e => e is Enemy);
                if (target == null)
                {
                    MapManager.Instance.isEnd = true;
                    return;
                }
                var mapManager = MapManager.Instance;
                astar = new(ref mapManager.map, mapManager.w, mapManager.h);
                path = astar.FindPath(postion, target.postion);
            }
            if (path != null && path.Count > 0)
            {
                _MoveTo(path[^1]);
                path.RemoveAt(path.Count - 1);
                if (path.Count == 0)
                {
                    target = null;
                    astar = null;
                }
            }
            else
            {
                throw new Exception("No path");
            }
        }

        private void _MoveTo(Vector2 pos)
        {
            var map = MapManager.Instance.map;
            MapObject target = map[pos.x, pos.y];
            if (target is Enemy enemy)
            {
                enemy.OnKilled();
            }
            map[postion.x, postion.y] = map[pos.x, pos.y];
            map[pos.x, pos.y] = this;
            postion.x = pos.x;
            postion.y = pos.y;
        }
    }
}
