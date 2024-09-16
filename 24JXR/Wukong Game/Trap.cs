// Date: 2024/09/15
// Author: ChaomengOrion

namespace OPP.Wukong
{
    public class Trap : MapObject
    {
        public override string Name => "障碍物";

        public override string GetIcon() => "█";

        public override bool IsPassable() => false;

        public override Layer GetLayer() => Layer.MAP;
    }
}
