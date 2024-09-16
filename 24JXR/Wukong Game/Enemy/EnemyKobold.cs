// Date: 2024/09/15
// Author: ChaomengOrion

namespace OPP.Wukong
{
    public class EnemyKobold : Enemy
    {
        public override string Name => "小妖怪";

        public override string GetIcon() => "\u001b[41;32mX\u001b[0m";

        public override void OnKilled()
        {
            base.OnKilled();
            Console.WriteLine($"\u001b[K \u001b[32m杀死了({postion})的小妖！\u001b[0m");
        }
    }
}
