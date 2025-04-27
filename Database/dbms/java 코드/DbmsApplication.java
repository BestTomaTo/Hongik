package edu.hongik.dbms;

import java.sql.*;

import org.jsoup.nodes.*;
import org.jsoup.select.Elements;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.jdbc.core.JdbcTemplate;

import edu.hongik.dbms.DbmsCrawler;

@SpringBootApplication
public class DbmsApplication implements CommandLineRunner {
	
	@Autowired
	private JdbcTemplate jdbcTemplate; // java db connection 
	
	private String url;
	private Connection conn; // connect specific db session with java
	private PreparedStatement pstmt;
	
	public DbmsApplication() {
		
		url = "jdbc:postgresql://127.0.0.1:5432/hongik?user=postgres&password=1234&ssl=false";
		try {			
			conn = DriverManager.getConnection(url);
			System.out.println("Connected!");
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
	}
	
	public static void main(String[] args) {
		SpringApplication.run(DbmsApplication.class, args);
	}
	
	
	@Override
	public void run(String... args) throws Exception {
		
		// create Crawler object
		// phd : h.cwxa41cyxn28_l
		// master : h.xrleu3h82rn1_l
		// under : h.kfl1x21a81ct_l
		jdbcTemplate.update("DELETE FROM students");
		DbmsCrawler Crawler = new DbmsCrawler(); // doc 생성
		Crawler.insertStudentsValue(conn, "h.cwxa41cyxn28_l");
		Crawler.insertStudentsValue(conn, "h.xrleu3h82rn1_l");
		Crawler.insertStudentsValue(conn, "h.kfl1x21a81ct_l");
		
	}

}
