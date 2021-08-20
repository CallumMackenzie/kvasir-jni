package jkvasir.engine;

import jkvasir.engine.rendering.RenderBase;

public class FrameManager {

	private long lastFrame = 0; // Nanoseconds
	private double deltaTime = 0; // Seconds
	private double targetDelta = 1.0 / 60.0; // Seconds
	private boolean capped = true;

	public FrameManager() {
	}

	public FrameManager(float FPS) {
		setFPS(FPS);
	}

	public FrameManager(double FPS) {
		setFPS(FPS);
	}

	public void setCapped(boolean cap) {
		capped = cap;
	}

	public void setFPS(double FPS) {
		targetDelta = 1.0 / FPS;
	}

	public void setFPS(float FPS) {
		setFPS((double) FPS);
	}

	public float deltaTime() {
		return (float) deltaTime;
	}

	public float delta() {
		return (float) deltaTime;
	}

	public double deltaTimeD() {
		return deltaTime;
	}

	public double deltaD() {
		return deltaTime;
	}

	public boolean nextFrameReady() {
		float timeLastFrameMicrosec = (System.nanoTime() - lastFrame) / 1000.f;
		if (!capped) {
			deltaTime = (double) timeLastFrameMicrosec / (1000.0 * 1000.0);
			lastFrame = System.nanoTime();
			return true;
		}
		float targetDeltaMicrosec = (float) (targetDelta * 1000.0 * 1000.0);
		if (timeLastFrameMicrosec >= targetDeltaMicrosec) {
			deltaTime = (double) timeLastFrameMicrosec / (1000.0 * 1000.0);
			lastFrame = System.nanoTime();
			return true;
		}
		return false;
	}

	public static double getRecommendedFPS(RenderBase base, int samples) {
		long start = System.nanoTime(); // Nanoseconds
		for (int i = 0; i < samples; ++i)
			base.swapBuffers();
		double duration = (double) ((System.nanoTime() - start) / 1000) / 1000.0; // Milliseconds
		double msPerFrame = duration / (double) samples;
		double fps = 1000.0 / msPerFrame;
		return (double) ((int) (fps + 5.0));
	}

	public static double getRecommendedFPS(RenderBase base) {
		return getRecommendedFPS(base, 30);
	}

}
