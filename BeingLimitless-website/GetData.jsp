<%
        String name[]=null;
        int i=0;
        String data = request.getParameter("data").trim();
        Class.forName("oracle.jdbc.OracleDriver");
        Connection con = DriverManager.getConnection("jdbc:orcale:thin:@localhost:1521:XE","akshit","akshit");
        PreparedStatement pst = con.prepareStatement("Select akshit.SubInterest.name from akshit.SubInterest,akshit.Interest where akshit.Interest.Name = ? and akshit.Interest.IID = akshit.SubInterest.PIID");
        pst.setString(1,data);
        ResultSet rs = pst.executeQuery();
        
        while(rs.next()){
   
            name[i]=rs.getString("name");
   
        }

%>  