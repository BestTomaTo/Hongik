package edu.hongik.dbms;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import org.jsoup.Jsoup;
import org.jsoup.nodes.*;
import org.jsoup.select.Elements;


public class DbmsCrawler {
	
	private static Document doc = null;
	// private int sid = 1;
	
	public DbmsCrawler() throws IOException{
		String url = "https://apl.hongik.ac.kr/lecture/dbms";
		
		doc = Jsoup.connect(url).get();
	}
	
	public void insertStudentsValue(Connection conn, String DegreeId) {
		Element DegreeElement = doc.getElementById(DegreeId);
		String DegreeName = DegreeElement.text().replace(" Students", "");
//		System.out.println(DegreeName);
		Element Degreeul = DegreeElement.nextElementSibling(); // <ul> 안에 <li> 향연
		Elements Degreeli = Degreeul.select("li");
		for (Element element : Degreeli) {
			String lilist = element.text();
			String[] lilistarr = lilist.split(",");
			
			String name = lilistarr[0].trim();
			String email = lilistarr[1].trim();
			int graduation = Integer.parseInt(lilistarr[2].trim());
			
			String sql = "INSERT INTO students (name, email, degree, graduation) VALUES (?, ?, ?, ?)";
            try (PreparedStatement stmt = conn.prepareStatement(sql)) {
                stmt.setString(1, name);
                stmt.setString(2, email);
                stmt.setString(3, DegreeName);
                stmt.setInt(4, graduation);
                stmt.executeUpdate();
            } catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
            // sid++;
		}
		
	}
}
