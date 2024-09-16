// Date: 2024/09/15
// Author: ChaomengOrion

namespace OPP.Wukong
{
    /// <summary>
    /// 地图上可移动的实体
    /// </summary>
    public abstract class Entity : MapObject
    {
        /// <summary>
        /// 每Tick刷新一次
        /// </summary>
        public abstract void OnTick();

        public override bool IsPassable() => true;

        public override Layer GetLayer() => Layer.CHAR;
    }
}
