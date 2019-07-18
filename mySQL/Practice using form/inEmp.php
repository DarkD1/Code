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
				<td><input type="text" name="employeeName" placeholder="Person Name" required=""> </td>
			</tr>
			<tr>
				<td>Street</td>
				<td><input type="text" name="street" placeholder="Street" required=""></td>
			</tr>
			<tr>
				<td>City</td> 
				<td><input type="text" name="city" placeholder="City" required=""></td>
			</tr>
			<tr>
				<td><input type="submit" name="submit" value= "Submit"></td>
			</tr>
		</table>
	</form>
	<?php  
		if(isset($_POST['submit'])){
			$sql = "INSERT INTO employee VALUES ('$_POST[employeeName]', '$_POST[street]', '$_POST[city]')";
			$res = mysqli_query($con, $sql);
			?>
			<script type="text/javascript">
				alert("Employee added successfully");
				window.location = window.location.href;
			</script>
			<?php
		}
	?>
</body>
</html>