<?php  
	include 'connection.php';
?>
<!DOCTYPE html>
<html>
<head>
	<title>Insert Data</title>
</head>
<body>
	<form method="POST">
		<table class="table table-bodered">
			<tr>
				<td>Person Name</td> 
				<td>
					<select name="employeeName">
						<?php
							$res = mysqli_query($con, "SELECT employeeName FROM employee;");
							while($row = mysqli_fetch_array($res)){
								echo "<option>";
								echo $row['employeeName'];
								echo "</option>";
							}
						?>
					</select>
				</td>
			</tr>
			<tr>
				<td>Company Name</td> 
				<td>
					<select name="companyName">
						<?php
							$res = mysqli_query($con, "SELECT companyName FROM company;");
							while($row = mysqli_fetch_array($res)){
								echo "<option>";
								echo $row['companyName'];
								echo "</option>";
							}
						?>
					</select>
				</td>
			</tr>
			<tr>
				<td>Salary</td> 
				<td><input type="number" name="salary" placeholder="Salary" required=""></td>
			</tr>
			<tr>
				<td><input type="submit" name="submit" value= "Submit"></td>
			</tr>
		</table>
	</form>
	<?php  
		if(isset($_POST['submit'])){
			$sql = "INSERT INTO works VALUES ('$_POST[employeeName]', '$_POST[companyName]', '$_POST[salary]')";
			$res = mysqli_query($con, $sql);
			?>
			<script type="text/javascript">
				alert("Salary added successfully");
				window.location = window.location.href;
			</script>
			<?php
		}
	?>
</body>
</html>