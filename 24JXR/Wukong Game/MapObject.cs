// Date: 2024/09/15
// Author: ChaomengOrion

namespace OPP.Wukong
{
    /// <summary>
    /// 地图上所有东西的基类
    /// </summary>
    public abstract class MapObject
    {
        public abstract string Name { get; }

        /// <summary>
        /// 获得当前物体的层级，用于绘制
        /// </summary>
        /// <returns>当前物体的层级</returns>
        public abstract string GetIcon();

        /// <summary>
        /// 获得当前物体的层级，用于绘制
        /// </summary>
        /// <returns>当前物体的层级</returns>
        public abstract Layer GetLayer();
        
        /// <summary>
        /// 表示该格子是否可通过
        /// </summary>
        public abstract bool IsPassable();

        public Vector2 postion;

        public enum Layer
        {
            MAP,
            CHAR
        }
    }
}
