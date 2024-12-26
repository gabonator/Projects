find dos -type f -not -name 'HISTORIK.EXE' -not -name 'CT-VOICE.DRV' -not -name 'GRAWAGA.CFG' -not -name 'FILESA.VGA' -not -name 'FILESA.CUR' -not -name 'FILESB.CUR' -not -name 'FILESB.VGA' -delete
node ../../cicojs/conv.js prehistorikopt.cpp prehistorik.js
node ../../cicojs/fsbuild.js dos resources.js
