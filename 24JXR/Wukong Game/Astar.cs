// Date: 2024/09/15
// Author: ChaomengOrion

namespace OPP.Wukong
{
    /// <summary>
    /// 实现A*寻路
    /// </summary>
    public class Astar
    {
        private readonly SortedDictionary<int, List<Vector2>> openTree = [];

        private readonly HashSet<Vector2> openSet = [];
        private readonly HashSet<Vector2> closeSet = [];
        private readonly Dictionary<Vector2, PathNode> allNodes = [];

        private Vector2 endPos;
        private Vector2 mapSize;


        /// <summary>
        /// 新建一个Map，包含了网格大小和障碍物信息
        /// </summary>
        /// <param name="map"></param>
        /// <param name="w"></param>
        /// <param name="h"></param>
        public Astar(ref MapObject[,] map, int w, int h)
        {
            mapSize = new Vector2(w, h);
            for (int i = 0; i < w; i++)
            {
                for (int j = 0; j < h; j++)
                {
                    Vector2 newPos = new(i, j);
                    allNodes.Add(newPos, new PathNode(!map[i, j].IsPassable(), newPos));
                }
            }
        }

        /// <summary>
        /// 寻路主要逻辑，通过调用该方法来获取路径信息，由一串Vector2代表
        /// </summary>
        /// <param name="beginPos"></param>
        /// <param name="endPos"></param>
        /// <returns></returns>
        public List<Vector2>? FindPath(Vector2 beginPos, Vector2 endPos)
        {
            List<Vector2> result = new List<Vector2>();

            this.endPos = endPos;
            Vector2 currentPos = beginPos;
            openSet.Add(currentPos);

            while (!currentPos.Equals(this.endPos))
            {
                _UpdatePath(currentPos);
                if (openSet.Count == 0) return null;

                currentPos = openTree.First().Value.First();
            }

            Vector2 path = currentPos;

            while (!path.Equals(beginPos))
            {
                result.Add(path);
                path = allNodes[path].parent!.position;
            }

            return result;
        }

        /// <summary>
        /// 寻路
        /// </summary>
        /// <param name="currentPos"></param>
        private void _UpdatePath(Vector2 currentPos)
        {
            closeSet.Add(currentPos);
            _RemoveOpen(currentPos, allNodes[currentPos]);
            List<Vector2> neighborNodes = _FindNeighbor(currentPos);
            foreach (Vector2 nodePos in neighborNodes)
            {

                PathNode newNode = new(false, nodePos);
                newNode.parent = allNodes[currentPos];

                int g;
                int h;

                g = currentPos.x == nodePos.x || currentPos.y == nodePos.y ? 10 : 14;

                int xMoves = Math.Abs(nodePos.x - endPos.x);
                int yMoves = Math.Abs(nodePos.y - endPos.y);

                int min = Math.Min(xMoves, yMoves);
                int max = Math.Max(xMoves, yMoves);
                h = min * 14 + (max - min) * 10;


                newNode.gCost = g + newNode.parent.gCost;
                newNode.hCost = h;

                PathNode originNode = allNodes[nodePos];

                if (openSet.Contains(nodePos))
                {
                    if (newNode.fCost < originNode.fCost)
                    {
                        _UpdateNode(newNode, originNode);
                    }
                }
                else
                {
                    allNodes[nodePos] = newNode;
                    _AddOpen(nodePos, newNode);
                }
            }
        }

        /// <summary>
        /// 将旧节点更新为新节点
        /// </summary>
        /// <param name="newNode"></param>
        /// <param name="oldNode"></param>
        private void _UpdateNode(PathNode newNode, PathNode oldNode)
        {
            Vector2 nodePos = newNode.position;
            int oldCost = oldNode.fCost;
            allNodes[nodePos] = newNode;
            List<Vector2> sameCost;

            if (openTree.TryGetValue(oldCost, out sameCost!))
            {
                sameCost.Remove(nodePos);
                if (sameCost.Count == 0) openTree.Remove(oldCost);
            }

            if (openTree.TryGetValue(newNode.fCost, out sameCost!))
            {
                sameCost.Add(nodePos);
            }
            else
            {
                sameCost = [nodePos];
                openTree.Add(newNode.fCost, sameCost);
            }
        }

        /// <summary>
        /// 将目标节点移出开启列表
        /// </summary>
        /// <param name="pos"></param>
        /// <param name="node"></param>
        private void _RemoveOpen(Vector2 pos, PathNode node)
        {
            openSet.Remove(pos);
            List<Vector2> sameCost;
            if (openTree.TryGetValue(node.fCost, out sameCost!))
            {
                sameCost.Remove(pos);
                if (sameCost.Count == 0) openTree.Remove(node.fCost);
            }
        }

        /// <summary>
        /// 将目标节点加入开启列表
        /// </summary>
        /// <param name="pos"></param>
        /// <param name="node"></param>
        private void _AddOpen(Vector2 pos, PathNode node)
        {
            openSet.Add(pos);
            List<Vector2> sameCost;
            if (openTree.TryGetValue(node.fCost, out sameCost!))
            {
                sameCost.Add(pos);
            }
            else
            {
                sameCost = [pos];
                openTree.Add(node.fCost, sameCost);
            }
        }

        /// <summary>
        /// 找到某节点的所有相邻节点
        /// </summary>
        /// <param name="nodePos"></param>
        /// <returns></returns>
        private List<Vector2> _FindNeighbor(Vector2 nodePos)
        {
            List<Vector2> result = [];

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    if (x == 0 && y == 0) continue;

                    Vector2 currentPos = new(nodePos.x + x, nodePos.y + y);

                    if (currentPos.x >= mapSize.x || currentPos.y >= mapSize.y || currentPos.x < 0 || currentPos.y < 0) continue; // 超出边界
                    if (closeSet.Contains(currentPos)) continue; // 位置已被闭合
                    if (allNodes[currentPos].isWall) continue;  // 遇到墙

                    if (Math.Abs(x * y) == 1)
                    {
                        if (allNodes[new Vector2(nodePos.x + x, nodePos.y)].isWall ||
                            allNodes[new Vector2(nodePos.x, nodePos.y + y)].isWall) continue; // 卡斜角
                    }

                    result.Add(currentPos);
                }
            }

            return result;
        }
    }
}