import jkvasir.*;
import jkvasir.math.*;
import jkvasir.world.*;
import jkvasir.engine.*;
import jkvasir.engine.rendering.*;

class Main extends KvasirEngine {
	public static void main(String[] args) {
		Main main = new Main();
		try {
			main.start();
		} catch (KvasirException e) {
			e.printStackTrace();
		}
	}

	public Main() {
		super(RenderBase.Type.TERMINAL, RenderBase.Type.DIRECTX, RenderBase.Type.VULKAN);
	}

	public void start() throws KvasirException {
		if (base.type() == RenderBase.Type.TERMINAL)
			start("Main", 64, 32);
		else
			start("Main", 720, 480);
	}

	Camera3D cam = new Camera3D();
	Shader shader = null;
	Mesh3D mesh = new Mesh3D();
	Vec3 euler = new Vec3();

	int nFrames = 0;
	float fpsSum = 0;

	protected boolean onStart() throws KvasirException {
		base.setClearColour(0xafbfcf);
		base.depthBufferActive(true);
		time.setFPS(FrameManager.getRecommendedFPS(base));
		fixedTime.setFPS(10);

		cam.getPos().setZ(-4);
		shader = Shader.default3D(base);

		if (!mesh.loadFromObj(base, "./res/cube.obj") || !mesh.makeMaterial(base))
			throw new KvasirException("Mesh could not be loaded.");

		mesh.setDiffuseTex(base, "./res/cbrick.png");
		return true;
	}

	protected void onUpdate() throws KvasirException {
		euler.addEquals(new Vec3(1, 1, 1).mul(time.delta()));
		mesh.rot = Quaternion.angleAxis(euler.x(), new Vec3(1, 1, 0));
		cam.debugControls(base, time.delta(), 1.4f, 3.f);

		base.clear();
		// base.renderMesh3D(cam, mesh, shader);
		shader.use();
		shader.uInt1("diff", 0);
		mesh.getBuffer().bindVAO();
		mesh.getMaterial().bind();
		shader.uMat4("transform", mesh.modelMatrix());
		shader.uMat4("view", cam.view().inverse());
		shader.uMat4("projection", cam.perspective());
		shader.uMat4("rot", Mat4.rotation(mesh.rot));
		shader.render(mesh.getNumTris());
		base.swapBuffers();
	}

	protected void onFixedUpdate() throws KvasirException {
		cam.setProperAspect(base);
	}

	protected void onClose() throws KvasirException {
		mesh.getBuffer().freeBuffer();
		mesh.getMaterial().freeTextures();
		shader.freeShader();
	}
}