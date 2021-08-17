import jkvasir.math.*;
import jkvasir.engine.*;

class Main {
	public static void main(String[] args) {
		System.out.println("Hello!");
		Vec4 v = new Vec4(1, 2, 3, 4);
		System.out.println(v.toString());
		FrameManager time = new FrameManager(10);
		for (int i = 0; i < 15; ++i)
			if (time.nextFrameReady())
			{
				System.out.println(Float.toString(time.delta()) + "s delta time.");
			}
	}
}