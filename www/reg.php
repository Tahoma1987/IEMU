// Thanks: DarkAng3l19
<?php
$dbhost = "localhost";
$dbuser = "root";
$dbpassword = "password";
$dbname = "iemu_ls";


if (isset($_POST['submit']))
{
    $login = $_POST['login'];
    $password = $_POST['password'];
    $email = $_POST['email'];
    if (strlen($login) <= 32)
    {
        if (empty($login))
            echo 'Fill login';
        elseif (empty($password))
            echo 'Fill password';
        elseif (empty($email))
            echo 'Fill E-mail';
        else
        {
            $password = md5($password);
            if ($msconn = mysql_connect($dbhost, $dbuser, $dbpassword))
            {
                if(!MYSQL_SELECT_DB($dbname))
                    exit('Select DB Error');
                $mdpass = md5($login).$password;
                $query = "INSERT INTO accounts (id, login, password, email, email_status, access, hash) VALUES ('', '".$login."', '".$mdpass."', '".$email."', '0', '0', '')";

                mysql_query($query);
                echo 'Account has been created.';
            }
        }
    }
}

?>





<form action="reg.php" method="POST">
    <b>Login:</b><input type="text" name="login"><br>
    <b>Password:</b>&nbsp;<input type="password" name="password"><br>
    <b>E-mail:</b>&nbsp;<input type="text" name="email"><br>
    <input type="submit" name="submit" value="Register">
</form>