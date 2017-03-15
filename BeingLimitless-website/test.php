<html>
    <head>
        <script src="http://code.jquery.com/jquery-1.9.1.js"></script>
        <script>
            function chk(){
        var name=document.getElementById('fname').value;    
            var dataString='name'+name;
            $.ajax({
            type:"post",
                url:"test1.php"
                data:dataString,
                cache:false,
                success:function(html){
                   $('#response').html(html);
                   }
            });
            return false;
            }
            
            /*
        $(document).ready(function(){
                          $.('#formsubmit').click(function(){
$.post("test1.php",{fname:$("#fname").val(),surname:$('#surname').val()},function(data){
                                                  $('#response').html(data);
                                              }
            );

        });
            });*/
        </script>
    </head>
    <body>
        <form>
        <input type="text" id="fname">
        <br><br><input type="button" value="Upvote" onclick="return chk()">
        </form>
        <p id="response"></p>        
    </body>

</html>