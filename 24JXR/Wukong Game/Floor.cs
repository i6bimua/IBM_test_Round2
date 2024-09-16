// Date: 2024/09/15
// Author: ChaomengOrion

namespace OPP.Wukong
{
    public class Floor : MapObject
    {
        public override string Name => "地面";

        public override string GetIcon() => " ";

        public override bool IsPassable() => true;

        public override Layer GetLayer() => Layer.MAP;
    }
}