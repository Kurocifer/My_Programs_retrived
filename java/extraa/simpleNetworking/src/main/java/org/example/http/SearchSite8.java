/*
package org.example.http;

import java.io.InputStream;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;

public class SearchSite8 {
  public static void main(String[] args) {
    var url = new URL("https://postman-echo.com/post");
    var encodedData = URLEncoder.encode("q=java", "ASCII");
    var contentType = "application/x-www-form-urlencoded";
    var conn = (HttpURLConnection) url.openConnection();
    conn.setInstanceFollowRedirects(false);
    conn.setRequestMethod("POST");
    conn.setRequestProperty("Content-Type", contentType );
    conn.setRequestProperty("Content-Length",
            String.valueOf(encodedData.length()));
    conn.setDoOutput(true);
    OutputStream os = conn.getOutputStream();
    os.write( encodedData.getBytes() );
    int response = conn.getResponseCode();
    if (response == HttpURLConnection.HTTP_MOVED_PERM
            || response == HttpURLConnection.HTTP_MOVED_TEMP) {
      System.out.println("Moved to: "+ conn.getHeaderField("Location"));
    } else {
      try (InputStream in = conn.getInputStream()) {
        Files.copy(in, Path.of("postman.txt"),
                StandardCopyOption.REPLACE_EXISTING);
      }
    }
  }


}
 */
