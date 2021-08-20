package jkvasir;

import jkvasir.engine.FrameManager;
import jkvasir.engine.rendering.RenderBase;
import jkvasir.engine.KvasirException;

public abstract class KvasirEngine {
	public FrameManager time = new FrameManager(60);
	public FrameManager fixedTime = new FrameManager(10);
	public RenderBase base = null;

	private RenderBase.Type[] rTypes = null;

	public KvasirEngine(RenderBase.Type type) {
		rTypes = new RenderBase.Type[] { type };
		base = new RenderBase(type);
	}

	public KvasirEngine(RenderBase.Type... types) {
		rTypes = types;
		base = new RenderBase(RenderBase.Type.NONE);
	}

	protected void start(String name, int width, int height) throws KvasirException {
		if (rTypes.length == 1) {
			if (!base.init(name, width, height))
				throw new KvasirException(
						"Render base (" + RenderBase.typeToString(rTypes[0]) + ") failed to initialize.");
		} else {
			boolean baseFound = false;
			for (int i = 0; i < rTypes.length; ++i)
				if (baseFound |= (base = new RenderBase(rTypes[i])).init(name, width, height))
					break;
				else if (base != null)
					base.destroy();
			if (!baseFound) {
				String basesTried = "";
				for (int j = 0; j < rTypes.length; ++j)
					basesTried += RenderBase.typeToString(rTypes[j]) + (j == rTypes.length - 1 ? "" : ", ");
				throw new KvasirException("Render base (" + basesTried + ") failed to initialize.");
			}
		}
		if (!onStart())
			throw new KvasirException("Method onStart returned false.");
		time.nextFrameReady();
		fixedTime.nextFrameReady();

		while (true) {
			if (time.nextFrameReady()) {
				base.pollEvents();
				onUpdate();
				if (base.shouldClose())
					break;
			}
			if (fixedTime.nextFrameReady())
				onFixedUpdate();
			perFrame();
		}
		onClose();
	}

	/**
	 * Override this to add additional update loops.
	 */
	protected void perFrame() throws KvasirException {
	}

	public void destroyBase() {
		if (base == null)
			return;
		base.destroy();
		base = null;
	}

	public abstract void start() throws KvasirException;

	protected abstract boolean onStart() throws KvasirException;

	protected abstract void onUpdate() throws KvasirException;

	protected abstract void onClose() throws KvasirException;

	protected abstract void onFixedUpdate() throws KvasirException;
}
