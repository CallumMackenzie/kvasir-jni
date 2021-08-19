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

	protected boolean onStart() throws RenderException {
		base.setClearColour(0xafbfcf);
		base.depthBufferActive(true);
		time.setFPS(300);

		cam.getPos().setZ(-4);
		shader = Shader.default3D(base);

		if (!mesh.loadFromObj(base, "D:\\3D Models\\isont.obj") || !mesh.makeMaterial(base))
			throw new RenderException("Mesh could not be loaded.");
		mesh.setDiffuseTex(base, 0xaabbff);
		return true;
	}

	protected void onUpdate() {
		euler.addEquals(new Vec3(1, 1, 1).mul(time.delta()));
		mesh.setRot(Quaternion.fromEuler(euler));
		mesh.setPos(mesh.getPos().add(new Vec3(0.5, 0.5, 0.5).mul(time.delta())));
		cam.aspect = (float) base.getAspect();
		cam.debugControls(base, time.delta(), 1.4f, 3.f);

		base.clear();
		base.renderMesh3D(cam, mesh, shader);
		base.swapBuffers();
		System.out.println("FPS: " + Double.toString(1.0 / time.deltaD()));
	}

	protected void onClose() {
		mesh.getBuffer().freeBuffer();
	}
}