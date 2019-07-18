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
				<td>Company Name</td> 
				<td><input type="text" name="companyName" placeholder="Company Name" required=""> </td>
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
			$sql = "INSERT INTO company VALUES ('$_POST[companyName]', '$_POST[city]')";
			$res = mysqli_query($con, $sql);
			?>
			<script type="text/javascript">
				alert("Company added successfully");
				window.location = window.location.href;
			</script>
			<?php
		}
	?>
</body>
</html>