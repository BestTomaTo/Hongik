package edu.hongik.dbms.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import java.sql.*;
import java.util.List;

//controller annotation
@RestController
@RequestMapping("/students")
public class DbmsController {
	
	@Autowired
	private JdbcTemplate jdbcTemplate;
	private String url;
	private Connection conn;
	private PreparedStatement stmt;
	public DbmsController() { // spring controller 생성자
		url = "jdbc:postgresql://127.0.0.1:5432/hongik?user=postgres&password=1234&ssl=false";
		try {
			conn = DriverManager.getConnection(url);
			System.out.println("connected2!");
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	// (1) 특정 이름을 가진 학생의 학위 유형 질의
	@GetMapping("/degree")
	@ResponseBody
	public String getStudentsDegree(
			@RequestParam(value="name") String name
			) throws SQLException {
		
		String sql = "SELECT degree FROM students WHERE name = ?";
        @SuppressWarnings("deprecation")
		List<String> results = jdbcTemplate.query(
        		sql, 
        		new Object[]{name},
        		(rs, rowNum) -> name + " : " + rs.getString("degree"));
		
        if (results.isEmpty()) {
        	System.out.println("No such student");
        	return "No such student";
        } else if(results.size() > 1){
        	System.out.println("There are multiple students with the same name. Please provide an email address instead.");
        	return "There are multiple students with the same name. Please provide an email address instead.";
        } else {
        	System.out.println(results.getFirst());
        	return results.getFirst();
        }        
        
	}
	
	
	// (2) 특정 이름을 가진 학생의 이메일 질의
	@GetMapping("/email")
	@ResponseBody
	public String getStudentsEmail(
			@RequestParam(value="name") String name
			) throws SQLException {
		
		String sql = "SELECT email FROM students WHERE name = ?";
		
		@SuppressWarnings("deprecation")
		List<String> results = jdbcTemplate.query(
				sql,
				new Object[]{name}, 
				(rs, rowNum) -> name + " : " + rs.getString("email"));
		
		
		if (results.isEmpty()) {
        	System.out.println("No such student");
        	return "No such student";
        } else if(results.size() > 1){
        	System.out.println("There are multiple students with the same name. Please contact the administrator by phone.");
        	return "There are multiple students with the same name. Please contact the administrator by phone.";
        } else {
        	System.out.println(results.getFirst());
        	return results.getFirst();
        }       
	}
	
	// (3) 학위별 학생의 수 반환
	@GetMapping("/stat")
	@ResponseBody
	public String getStudentsCount(
			@RequestParam(value="degree") String degree
			) throws SQLException {
		String sql = "SELECT count(*) FROM students WHERE degree = ?";
		
		@SuppressWarnings("deprecation")
		int count = jdbcTemplate.queryForObject(sql, new Object[]{degree},  Integer.class);
		String results = "Number of " + degree + "'s student : " + count;
		return results;
	}
	
	// (4) 신규 학생의 등록
	@PutMapping("/register")
	@ResponseBody
	public String registerStudents(
			@RequestParam(value="name") String name,
			@RequestParam(value="email") String email,
			@RequestParam(value="degree") String degree,
			@RequestParam(value="graduation") int graduation) {
		
		// insert 문 삽입
		try {
			String mainSQL = "INSERT INTO students (name, email, degree, graduation) VALUES (?, ?, ?, ?)";
			jdbcTemplate.update(mainSQL, new Object[]{name, email, degree, graduation});
		} catch(DataAccessException e) {
			// 삽입 실패 시 구문 반환 
			return "Already registerd";			
		}		
		
		return "Registration successful";
	}
	
}
