import jkvasir.math.*;
import jkvasir.world.*;
import jkvasir.engine.rendering.*;
import jkvasir.*;

class Main extends KvasirEngine {
	public static void main(String[] args) {
		Main main = new Main();
		try {
			main.start();
		} catch (RenderException e) {
			e.printStackTrace();
		}
	}

	public Main() {
		super(RenderBase.Type.OPENGL);
	}

	public void start() throws RenderException {
		start("Main", 720, 480);
	}

	Camera3D cam = new Camera3D();
	Shader shader = null;
	Mesh3D mesh = new Mesh3D();
	Vec3 euler = new Vec3();

	int nFrames = 0;
	float fpsSum = 0;

	protected boolean onStart() throws RenderException {
		base.setClearColour(0xafbfcf);
		base.depthBufferActive(true);
		time.setFPS(300);
		fixedTime.setFPS(2);

		cam.getPos().setZ(-4);
		shader = Shader.default3D(base);

		if (!mesh.loadFromObj(base, "./res/cube.obj") || !mesh.makeMaterial(base))
			throw new RenderException("Mesh could not be loaded.");
		mesh.setDiffuseTex(base, "./res/cbrick.png");
		return true;
	}

	protected void onUpdate() throws RenderException {
		euler.addEquals(new Vec3(1, 1, 1).mul(time.delta()));
		mesh.rot = Quaternion.angleAxis(euler.x(), new Vec3(1, 1, 0));
		cam.debugControls(base, time.delta(), 1.4f, 3.f);
		mesh.makeMaterial(base);
		mesh.setDiffuseTex(base, 0xffffff);

		base.clear();
		base.renderMesh3D(cam, mesh, shader);
		base.swapBuffers();

		++nFrames;
		fpsSum += (float) (1.0 / time.deltaD());
		System.out.println("FPS: " + Float.toString(fpsSum / (float) nFrames));
		if (nFrames >= 500) {
			nFrames = 0;
			fpsSum = 0;
		}
	}

	protected void onFixedUpdate() throws RenderException {
		cam.aspect = (float) base.getAspect();
	}

	protected void onClose() throws RenderException {
		mesh.getBuffer().freeBuffer();
	}
}