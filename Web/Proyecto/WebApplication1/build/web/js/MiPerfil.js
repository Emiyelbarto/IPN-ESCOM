$(document).ready(function(){
    $('.campoOculto').hide();
    
    $('#btnModificar').click(function(){
        botonModificar();
        $('#btnGuardar').addClass("button");
    });
    
    $('#btnGuardar').click(function(){
        validarDatos();
    });
    
    $('#btnCancelar').click(function(){
        $(location).attr('href',"Catalogo.jsp");
    });
});

function botonModificar(){
    $('.campoOculto').show();
    $('.soloTexto').hide();
    $('#btnModificar').hide();
}

function validarDatos(){
    var nombre = $('#txtNombre').val();
    var apellido = $('#txtApellido').val();
    var dni = $('#txtDni').val();
    var departamento = $('#txtDepartamento').val();
    var provincia = $('#txtProvincia').val();
    var distrito = $('#txtDistrito').val();
    var direccion1 = $('#txtDireccion1').val();
    var telefono = $('#txtTelefono').val();
    
    if(nombre == ""){
        alert("El campo nombre no puede estar vacio");
        $('#txtNombre').focus();
        botonModificar();
    }
    else if(apellido == ""){
        alert("El campo apellido no puede estar vacio");
        $('#txtApellido').focus();
        botonModificar();
    }
    else if(dni == ""){
        alert("El campo dni no puede estar vacio");
        $('#txtDni').focus();
        botonModificar();
    }
    else if(departamento == ""){
        alert("El campo departamento no puede estar vacio");
        $('#txtDepartamento').focus();
        botonModificar();
    }
    else if(provincia == ""){
        alert("El campo provincia no puede estar vacio");
        $('#txtProvincia').focus();
        botonModificar();
    }
    else if(distrito == ""){
        alert("El campo distrito no puede estar vacio");
        $('#txtDistrito').focus();
        botonModificar();
    }
    else if(direccion1 == ""){
        alert("El campo direccion1 no puede estar vacio");
        $('#txtDireccion1').focus();
        botonModificar();
    }
    else if(telefono == ""){
        alert("El campo telefono no puede estar vacio");
        $('#txtTelefono').focus();
        botonModificar();
    }
    else{
        $('#frmModificarUsuario').submit();
    }
}