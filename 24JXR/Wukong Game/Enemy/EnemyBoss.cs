// Date: 2024/09/15
// Author: ChaomengOrion

namespace OPP.Wukong
{
    public class EnemyBoss : Enemy
    {
        public override string Name => "妖怪头目";

        public override string GetIcon() => "\u001b[1;41;32mT\u001b[0m";

        public override void OnKilled()
        {
            base.OnKilled();
            Console.WriteLine($"\u001b[K \u001b[32m杀死了({postion})的头目！\u001b[0m");
        }
    }
}
