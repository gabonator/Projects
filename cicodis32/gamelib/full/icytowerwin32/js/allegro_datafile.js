function decompressLZSS(input) {
    if (input.length < 4) return new Uint8Array(0);

    // Convert first 4 bytes to string for comparison
    const header = String.fromCharCode(...input.subarray(0, 4));

    if (header === "slh.") {
        return input.subarray(4); // raw copy
    }

    if (header !== "slh!") return new Uint8Array(0);

    const N = 4096;
    const F = 18;
    const THRESHOLD = 2;

    const text_buf = new Uint8Array(N + F - 1);
    let r = N - F;
    let flags = 0;

    let in_pos = 4;

    const output = [];

    const getByte = () => {
        if (in_pos >= input.length) return null;
        return input[in_pos++];
    };

    while (true) {
        // Load new flags byte if needed
        if (((flags >>= 1) & 0x100) === 0) {
            const c = getByte();
            if (c === null) break;
            flags = c | 0xFF00;
        }

        if (flags & 1) {
            // Literal byte
            const c = getByte();
            if (c === null) break;
            output.push(c);
            text_buf[r] = c;
            r = (r + 1) & (N - 1);
        } else {
            // Reference to previous string
            const iByte = getByte();
            const jByte = getByte();
            if (iByte === null || jByte === null) break;

            let i = iByte | ((jByte & 0xF0) << 4);
            let j = (jByte & 0x0F) + THRESHOLD;

            for (let k = 0; k <= j; k++) {
                const c = text_buf[(i + k) & (N - 1)];
                output.push(c);
                text_buf[r] = c;
                r = (r + 1) & (N - 1);
            }
        }
    }

    return Uint8Array.from(output);
}

function loadAllegroDatafile(filedata) {
    const be32 = (data, pos) => {
        if (pos + 4 > data.length) throw new Error('Unexpected EOF');
        return (data[pos] << 24) | (data[pos + 1] << 16) | (data[pos + 2] << 8) | data[pos + 3];
    }

    const read4 = (data, pos) => {
        if (pos + 4 > data.length) throw new Error('Unexpected EOF');
        return String.fromCharCode(...data.subarray(pos, pos + 4));
    }

    if (filedata.length < 8) throw new Error('File too small');
    let pos = 0;

    const magic = read4(filedata, pos);
    pos += 4;
    if (magic !== 'ALL.') throw new Error('Not an Allegro datafile');

    const objectCount = be32(filedata, pos);
    pos += 4;

    const resources = [];

    for (let obj = 0; obj < objectCount; obj++) {
        let origName = '';

        while (true) {
            if (pos + 4 > filedata.length) throw new Error('Unexpected EOF');
            const id = read4(filedata, pos);

            if (id === 'prop') {
                pos += 4;
                if (pos + 4 > filedata.length) throw new Error('Unexpected EOF');
                const pname = read4(filedata, pos);
                pos += 4;

                const len = be32(filedata, pos);
                pos += 4;

                if (pos + len > filedata.length) throw new Error('Unexpected EOF');
                const val = String.fromCharCode(...filedata.subarray(pos, pos + len));
                pos += len;

                if (pname === 'NAME') origName = val;
                continue;
            }

            // payload
            if (pos + 12 > filedata.length) throw new Error('Unexpected EOF');
            const payloadType = read4(filedata, pos);
            pos += 4;

            const payloadSize = be32(filedata, pos);
            pos += 4;
            const payloadSize2 = be32(filedata, pos);
            pos += 4;

            if (payloadSize !== payloadSize2) throw new Error('Payload size mismatch');
            if (pos + payloadSize > filedata.length) throw new Error('Unexpected EOF');

            if (payloadType === 'info') {
                pos += payloadSize;
                break;
            }

            const payload = filedata.subarray(pos, pos + payloadSize);
            pos += payloadSize;

            resources.push({type:payloadType.split(" ").join(""), name:origName, payload:payload});
            break; // done with this object
        }
    }

    return resources;
}