package jkvasir.engine;

public class KvasirException extends Throwable {
	public static enum Severity {
		FATAL, RETRY, OK
	};

	private Severity severity;

	public KvasirException(String msg, Severity sev) {
		super(msg);
		severity = sev;
	}

	public KvasirException(String msg) {
		this(msg, Severity.FATAL);
	}

	public KvasirException(Severity sev) {
		this("", sev);
	}

	public Severity getSeverity() {
		return severity;
	}

}
