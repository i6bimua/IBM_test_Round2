// Date: 2024/09/15
// Author: ChaomengOrion

namespace OPP.Wukong
{
    public abstract class Enemy : Entity
    {
        protected bool m_isAlive = true;

        public override void OnTick()
        {
            if (!m_isAlive) return;
            return;
        }

        public virtual void OnKilled()
        {
            m_isAlive = false;
            MapManager.Instance.entities.Remove(this);
            MapManager.Instance.map[postion.x, postion.y] = new Floor();
        }
    }
}
