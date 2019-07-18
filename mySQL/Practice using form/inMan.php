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
				<td>Employee Name</td> 
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
				<td>Manager Name</td>
				<td>
					<select name="managerName">
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
				<td><input type="submit" name="submit" value= "Submit"></td>
			</tr>
		</table>
	</form>
	<?php  
		if(isset($_POST['submit'])){
			$sql = "INSERT INTO manages VALUES ('$_POST[employeeName]', '$_POST[managerName]');";
			$res = mysqli_query($con, $sql);
			?>
			<script type="text/javascript">
				alert("Person added successfully");
				window.location = window.location.href;
			</script>
			<?php
		}
	?>
</body>
</html>