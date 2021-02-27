<%-- 
    Document   : mensaje2
    Created on : 13-dic-2016, 13:46:00
    Author     : Manuel
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link type="text/css" rel="stylesheet" href="css/css1.css" />
        <title>JSP Page</title>
    </head>
    <body>
        <h1 align="center">
            <%
                if(request.getParameter("mens")!=null){
                    out.println(request.getParameter("mens"));
                }
            %>
        </h1>
        <div align="center"><img src="Imagen/log.jpg" width="178" height="178"><br>
        </div>
        <h2 align="center">
            <a href="Catalogo.jsp">Regresar al menú</a>
        </h2>
    </body>
</html>
