const getUploadObj = function() {
    try {
        return new ActiveXObject("TXFTNActiveX.FTNUpload");  // IE上传组件
    } catch(err) {
        if (supportFlash()) {
            const str = '<object type="application/x-shockware-flash"></object>';
            return $(str).appendTo($('body'));
        } else {
            const str = '<input name="file" type="file" />'; // 表单上传
            return $(str).appendTo($('body'));
        }
    }
};

// 不符合封闭开放法则

const getActiveUploadObj = function() {
    try {
        return new ActiveXObject("TXFTNActiveX.FTNUpload");  // IE上传组件
    } catch(err) {
        return false;
    }
};

const getFlashUploadObj = function() {
    if (supportFlash()) {
        const str = '<object type="application/x-shockware-flash"></object>';
        return $(str).appendTo($('body'));
    }
    return false;
};

const getFormUploadObj = function() {
    const str = '<input name="file" type="file" />'; // 表单上传
    return $(str).appendTo($('body'));
}

const iteratorUploadObj = function() {
    for (let i = 0, fn; fn = arguments[i++]) {
        const uploadObj = fn();
        if (uploadObj !== false) {
            return uploadObj;
        }
    }
};

const uploadObj = iteratorUploadObj(getActiveUploadObj, getFlashUploadObj, getFormUploadObj);

const getWebkitUploadObj = function() {};

const getHTML5UploadObj = function () {};

const newUploadObj = iteratorUploadObj(getActiveUploadObj, getFlashUploadObj, getFormUploadObj, getWebkitUploadObj, getHTML5UploadObj);