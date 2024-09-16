// Date: 2024/09/15
// Author: ChaomengOrion

namespace OPP.Wukong
{
    public struct Vector2(int x, int y)
    {
        public int x = x;

        public int y = y;

        public override readonly bool Equals(object? obj)
        {
            if (obj is not Vector2) return false;
            return x == ((Vector2)obj).x && y == ((Vector2)obj).y;
        }

        public override readonly int GetHashCode() => x ^ y * 256;

        public override readonly string ToString() => x + "," + y;

        public static bool operator ==(Vector2 a, Vector2 b) => a.Equals(b);

        public static bool operator !=(Vector2 a, Vector2 b) => !a.Equals(b);
    }
}