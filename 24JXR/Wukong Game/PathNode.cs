// Date: 2024/09/15
// Author: ChaomengOrion

namespace OPP.Wukong
{
    public class PathNode
    {
        public PathNode(bool isWall, Vector2 position)
        {
            this.isWall = isWall;
            this.position = position;
        }

        public readonly Vector2 position;

        public bool isWall;

        public PathNode? parent;

        public int gCost;

        public int hCost;

        public int fCost
        {
            get
            {
                return gCost + hCost;
            }
        }
    }
}