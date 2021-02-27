$(document).ready(function(){
    $('#txtModificarImagen').attr('disabled','disabled');
    
    $('#btnCancelar').click(function(){
        history.back();
    });
    
    $('#btnGuardar').click(function(){
        validarDatos();
    });
    
    $('#SelectImagenActual').click(function(){
        $('#txtImagen').removeAttr('disabled');
        $('#txtModificarImagen').attr('disabled','disabled');
    });
    
    $('#SelectModificarImagen').click(function(){
        $('#txtImagen').attr('disabled','disabled');
        $('#txtModificarImagen').removeAttr('disabled');
    });
});

function validarDatos(){
    var nombreCP = $('#txtNombreCP').val();
    var nombreMP = $('#txtNombreMP').val();
    var descripcionP = $('#txtDescripcionP').val();
    var precioP = $('#txtPrecioP').val();
    var imagenP = $('#txtImagen').val();
    
    if(nombreCP == ""){
        alert("El campo clase producto no puede estar vacio");
        $('#txtNombreCP').focus();
    }
    else if(nombreMP == ""){
        alert("El campo marca producto no puede estar vacio");
        $('#txtNombreMP').focus();
    }
    else if(descripcionP == ""){
        alert("El campo descripcion producto no puede estar vacio");
        $('#txtDescripcionP').focus();
    }
    else if(precioP == ""){
        alert("El campo precio producto no puede estar vacio");
        $('#txtPrecioP').focus();
    }
    else if(imagenP == ""){
        alert("El campo imagen producto no puede estar vacio");
        $('#txtImagen').focus();
    }
    else{
        $('#frmModificarProd').submit();
    }
}