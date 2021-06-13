package cc;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;

public class Dosya {
	private String yol;
	public Dosya(String yol) {
		this.yol=yol;
	}
	public String Oku() throws IOException {
		Path path=FileSystems.getDefault().getPath(yol);
		return new String(Files.readAllBytes(path), StandardCharsets.UTF_8);
	}
}